import React from 'react';
import 'styles/index.scss';
import {signal} from "core/core";
import {eventConfig as ec} from 'core/eventConfig';
import Button from 'reactComponents/Button';

export default class App extends React.Component {
  render() {
    return (
      <div id="bg">
        This is app.jx
        <Button label="HI" onClick={this.handleButtonClick.bind(this)}/>
      </div>
    )
  }
  handleButtonClick(){
    document.getElementById("bg").innerHTML = "BUTTON CLICKED" + window.location.href + " taco";
    window.location.href += "?projucer://data=1&d2=2";
  }
}


