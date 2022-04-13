!function(){var Utils_log=function(t){console.log&&console.log("[marquee]---\x3e"+t)};function MarqueePlugin(){if(this.container=document.querySelector("#marquee"),this.container){this.containerParent=this.container.parentNode,this.canvas=document.createElement("canvas"),this.canvas.style.width="100%",this.canvas.style.height="100%",this.canvas.width="1920",this.canvas.height="1080",this.type="text",this.container.appendChild(this.canvas),!0,this.context=this.canvas.getContext("2d"),this.font="bold 微软雅黑 20px",this.align="center",this.fillStyle="#fff",this.textContent="Hello ",this.contentImage=null,this.imageW=0,this.imageH=0;var containerId="marquee";setInterval(function(){var container=document.querySelector("#"+containerId),marqueeCanvas=document.querySelector("#"+containerId+" canvas");if(!container){var marqueeId="hd_marquee_"+Math.floor(1e3*Math.random());containerId=marqueeId;var marquee=document.createElement("div");marquee.id=marqueeId,this.containerParent.appendChild(marquee),container=marquee,marqueeCanvas=document.querySelector("#"+marqueeId+" canvas")}marqueeCanvas||container.appendChild(this.canvas)}.bind(this),1e4),setInterval(function(){document.querySelector("#dp #plugin")||alert("文档出现异常")},3e3)}}MarqueePlugin.prototype.init=function(obj){if(this.marqueeInfo=obj,this.type=this.marqueeInfo.type||"text",this.container){if(this.marqueeInfo.action&&0<this.marqueeInfo.action.length){var endObj={index:this.marqueeInfo.action.length,duration:5e3,start:{xpos:this.marqueeInfo.action[this.marqueeInfo.action.length-1].end.xpos,ypos:this.marqueeInfo.action[this.marqueeInfo.action.length-1].end.ypos,alpha:1},end:{xpos:this.marqueeInfo.action[0].start.xpos,ypos:this.marqueeInfo.action[0].start.ypos,alpha:1}};this.marqueeInfo.action.push(endObj)}this.create(this.type)}},MarqueePlugin.prototype.create=function(t){var startPosx=this.marqueeInfo.action[0].start.xpos*this.canvas.width,startPosy=this.marqueeInfo.action[0].end.ypos*this.canvas.height;switch(t){case"text":this.fillStyle=this.marqueeInfo.text.color.replace("0x","#")||"#000000",this.font="bold "+this.marqueeInfo.text.font_size+"px "+this.marqueeInfo.text.font,Utils_log(this.font),this.textContent=this.marqueeInfo.text.content,Utils_log(this.textContent),this.context.font=this.font,this.context.textAlign="left",this.context.fillStyle=this.fillStyle,this.context.fillText(this.textContent,startPosx,startPosy);break;case"image":this.contentImage=new Image,this.contentImage.src=this.marqueeInfo.image_url,this.contentImage.onload=function(){this.context.drawImage(this.contentImage,0,0,this.contentImage.width,this.contentImage.height,startPosx,startPosy,this.marqueeInfo.width,this.marqueeInfo.height)}.bind(this)}},MarqueePlugin.prototype.startTimerToRun=function(){var _this=this;this.lastStart=null;var currentStyle=_this.tweenType(),index=0;function paraseInfo(val,t){var startposL=val.xpos*_this.boxW,startpostT=val.ypos*_this.boxH;(1<val.xpos||1<val.ypos)&&(startposL=val.xpos,startpostT=val.ypos);var startAl=val.alpha;return"s"==t&&setDomPostion(startposL,startpostT,startAl),{l:startposL,t:startpostT,a:startAl}}function setDomPostion(l,t,a){switch(_this.context.clearRect(0,0,_this.canvas.width,_this.canvas.height),_this.type){case"image":_this.context.drawImage(_this.contentImage,0,0,_this.contentImage.width,_this.contentImage.height,l,t,_this.marqueeInfo.width,_this.marqueeInfo.height);break;case"text":_this.context.fillText(_this.textContent,l,t),_this.canvas.style.opacity=a}}function getRandomEndpos(s,end){for(var value=Math.round(Math.random()*end);Math.abs(value-s)<50;)value=Math.round(Math.random()*end);return value}function resetData(ind){var start,end,during,startInfo,endInfo;if(_this.boxW=_this.canvas.width,_this.boxH=_this.canvas.height,_this.marqueeInfo.action&&0<_this.marqueeInfo.action.length)start=_this.marqueeInfo.action[ind].start,end=_this.marqueeInfo.action[ind].end,during=_this.marqueeInfo.action[ind].duration,startInfo=paraseInfo(start,"s"),endInfo=paraseInfo(end);else{if(null==this.lastStart){var xpos=Math.random()*_this.boxW,ypos=Math.random()*_this.boxH;start={xpos:xpos,ypos:ypos,alpha:1},this.lastStart=start}startInfo=paraseInfo(this.lastStart,"s"),end={xpos:getRandomEndpos(xpos,_this.boxW),ypos:getRandomEndpos(ypos,_this.boxH),alpha:1},this.lastStart=end,during=1e3*Math.ceil(5*Math.random()),endInfo=paraseInfo(end)}!function(start,end,during){var timerIndex=0;_this.clearTimer(),_this.timer=setInterval(function(){if(during<timerIndex)return _this.marqueeInfo.action&&0<_this.marqueeInfo.action.length&&(index>=_this.marqueeInfo.action.length-1?(_this.clearTimer(),index=0):index+=1),timerIndex=0,void resetData(index);setDomPostion(currentStyle(timerIndex+=10,start.l,end.l,during),currentStyle(timerIndex,start.t,end.t,during),currentStyle(timerIndex,start.a,end.a,during))},10)}(startInfo,endInfo,during)}resetData(index)},MarqueePlugin.prototype.tweenType=function(){return function(t,s,e,d){return t/d*(e-s)+s}},MarqueePlugin.prototype.clearTimer=function(){-1!=this.timer&&clearInterval(this.timer)},MarqueePlugin.prototype.close=function(){this.clearTimer(),this.context.clearRect(0,0,this.canvas.width,this.canvas.height)},window.MarqueePlugin=MarqueePlugin}();