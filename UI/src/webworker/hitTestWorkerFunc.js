

//this function is turned into a string, then loaded as a web worker.
// no outside references allowed.
//work the worker does when receiving a message
export default function hitTestWorkerFunc(){
  importScripts('https://cdnjs.cloudflare.com/ajax/libs/three.js/88/three.js');
  let {Box3, Sphere} = THREE;
  let hittableWebWorkerHitBoxes = [];

  //performs hit tests agains all boxes
  function performHitTest({requestId, webWorkerHitBox1, webWorkerHitBoxes=hittableWebWorkerHitBoxes}){
    let hitteeComponentId = webWorkerHitBox1.componentId;

    let box1box3 = createAppropriateThreeHitbox({hitBox:webWorkerHitBox1.hitBox});

    //console.log(`performing hit test for hitteeComponentId: ${hitteeComponentId} against ${webWorkerHitBoxes.length} hittable boxes`);
    let doesIntersect = false;
    let intersectResult = {doesIntersect, hitteeComponentId, hitComponentId:undefined};

    for(let i = 0, len = webWorkerHitBoxes.length; i < len; ++i){
      let webWorkerHitBox2 = webWorkerHitBoxes[i];

      //don't let things hit themselves. e.g. a Player is a hitter and a hittee.
      if(webWorkerHitBox2.componentId == webWorkerHitBox1.componentId){
        continue;
      }
      //let box2box3 = new Box3().set(webWorkerHitBox2.hitBox.min, webWorkerHitBox2.hitBox.max);
      let box2box3 = createAppropriateThreeHitbox({hitBox:webWorkerHitBox2.hitBox});
      //let doesIntersect = box1box3.intersectsBox(box2box3);
      let doesIntersect = intersects(box1box3, box2box3);
      if(doesIntersect === true){
        let hitComponentId = webWorkerHitBox2.componentId;

        intersectResult.doesIntersect = true;
        intersectResult.hitComponentId = hitComponentId;
        break;
      }
    }
    if(intersectResult.doesIntersect){
      let webWorkerResponse = intersectResult;
      webWorkerResponse.command = 'hitTestResult';
      postMessage(webWorkerResponse);
    }
  }

  function intersects(box1, box2){
    let doesIntersect = false;
    if(box2 instanceof Sphere){
      doesIntersect = box1.intersectsSphere(box2);
    }else{
      doesIntersect = box1.intersectsBox(box2);
    }
    return doesIntersect;
  }
  function createAppropriateThreeHitbox({hitBox}){
    let {type} = hitBox;
    let box1box3;
    if(type === 'Sphere'){
      box1box3 = new Sphere(hitBox.center, hitBox.radius);
    }else{
      box1box3 = new Box3().set(hitBox.min, hitBox.max);
    }
    return box1box3;
  }

  function registerHittableWebWorkerHitBox({componentId, hitBox, hitBoxes=hittableWebWorkerHitBoxes}){
    hitBoxes.push({componentId, hitBox});
  }

  function unregisterHittableWebWorkerHitBox({componentId, hitBoxes=hittableWebWorkerHitBoxes}){
    let hitIndex = hitBoxes.findIndex((element)=>{
      return element.componentId === componentId;
    });
    if(hitIndex < 0){return;}
    hitBoxes.splice(hitIndex, 1);//remove hittable component from
  }

  function updateComponentHitBox({componentId, hitBox, hitBoxes=hittableWebWorkerHitBoxes}){
    for(let i = 0, len=hitBoxes.length; i < len; ++i){
      let hb = hitBoxes[i];
      if(hb.componentId == componentId){
        hb.hitBox = hitBox;
        break;
      }
    }
  }

  function destroy(){
    hittableWebWorkerHitBoxes = [];
  }

  onmessage = function(e){
    let data = e.data;
    let command = data.command;

    switch(command){
      case 'performHitTest':{
        performHitTest(data);
        break;
      }
      case 'registerHittableWebWorkerHitBox':{
        registerHittableWebWorkerHitBox(data);
        break;
      }
      case 'unregisterHittableWebWorkerHitBox':{
        unregisterHittableWebWorkerHitBox(data);
        break;
      }
      case 'updateComponentHitBox':{
        updateComponentHitBox(data);
        break;
      }
      case 'destroy':{
        destroy(data);
        break;
      }
      default:{
        console.log(`web worker did not recognize command ${command}`);
      }
    }
  }
}
