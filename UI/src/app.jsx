import React from 'react';
import 'styles/index.scss';
import {signal} from "core/core";
import {eventConfig as ec} from 'core/eventConfig';
import Button from 'reactComponents/Button';

let messageId = 0;
export default class App extends React.Component {
  render() {
    return (
      <div id="bg">
        This is app.jx 2
        <Button label="HI" onClick={this.handleButtonClick.bind(this)}/>
        <div id="output">output</div>
      </div>
    )
  }
  componentWillMount(){
    window.addEventListener("hashchange", this.handleHashChange, false);

  }
  componentWillUnmount(){
    window.removeEventListener("hashChange", this.handleHashChange);
  }
  handleHashChange(){
    document.getElementById("output").innerHTML = `hash is: ${location.hash}`;
  }
  handleButtonClick(){
    ++messageId;
    const data = {messageId, test: "message", is:{ this: 1 }, arr:['a', {b: 'baby'}, 33 ] };
    const endcodedData = encodeURIComponent(JSON.stringify(data));
    const url = `${window.location.origin}${window.location.pathname}?native-bridge://data=${endcodedData}`;
    document.getElementById("output").innerHTML = "url is: " + url;
    window.location.href = url;
  }
}


