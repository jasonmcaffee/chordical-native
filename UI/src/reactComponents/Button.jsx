import React from 'react';
import 'styles/index.scss';
import {signal, eventConfig as ec} from "core/core";

export default class Button extends React.Component {
  constructor(){
    super();
    this.state = {};
  }

  componentWillMount(){
    // signal.registerSignals(this);
  }
  componentWillUnmount(){
    // signal.unregisterSignals(this);
  }
  render(){
    let {label, onClick, className} = this.props;
    className = className || "button-component";
    return(
      <div className={className} onClick={onClick}>
        {label}
      </div>
    );
  }

}