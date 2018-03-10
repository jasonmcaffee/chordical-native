import {signal, eventConfig as ec} from 'core/core';

export function NewWorker(fn, signalEventOnMessage=ec.webworker.message){
  let worker = createWorkerFromFunctionString(fn.toString());
  worker.onmessage = (e)=>{
    signal.trigger(signalEventOnMessage, e.data);
  };
  return worker;
}

function createWorkerFromFunctionString(str){
  let blobURL = URL.createObjectURL(new Blob(['(',
      str,
      ')()'], {
      type: 'application/javascript'
    }));
  let worker = new Worker(blobURL);
  return worker;
}