const hgl = require('hedonGL');
class Dot{
	constructor(vec) {
		vec = vec || [];
		this.vec = [...Array(3)].map( (v,i)=> vec[i] || 0 );
	}
	draw(){
		hgl.glVertex3f(...this.vec);
	}
};
module.exports = Dot;