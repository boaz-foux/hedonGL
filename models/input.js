const 
	store = require('../stores/inputs'),
	hgl = require('./hgl');

module.exports = Input;

class Input {
	constructor(window){
	const _store = store(this);
	hgl.glfwSetKeyCallback(window,
		(win , key,scancode,action,mods) => {
			if(window != win) {
				return;
			}
			_store.dispach({
				type : 'key',
				key,
				scancode,
				action,
				mods
			});
		});
	hgl.glfwSetMouseButtonCallback( window,
		(win,leftClick,action) => {
			if(window != win) {
				return;
			}
			_store.dispach({
				type : 'mouseButton',
				leftClick,
				action
			});
		});
	hgl.glfwSetCursorPosCallback( window,
		(win,x,y) => {
			if(window != win) {
				return;
			}
			_store.dispach({
				type : 'cursorPosition',
				x,y
			});
		});
	hgl.glfwSetCursorEnterCallback( window,
		(win,inFrame) => {
			if(window != win) {
				return;
			}
			_store.dispach({
				type : 'cursorEnter',
				inFrame
			});
		});
	hgl.glfwSetScrollCallback( window,
		(win, yaxis,xaxis) => {
			if(window != win) {
				return;
			}
			_store.dispach({
				type : 'scroll',
				yaxis,xaxis
			}); 
		});
	}
};
