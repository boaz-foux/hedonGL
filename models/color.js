const hgl = require('hedonGL');
class Color{
	constructor(vec) {
		// super();
		vec = vec || [];
		this.vec = [...Array(3)].map( (v,i)=> vec[i] || 0 );
	}
	draw(){
		hgl.glColor3f(...this.vec);
	}
};
module.exports = Color;