const hgl = require('hedonGL');
class Polygon {
	constructor(props,children) {
		this.children = children;
	}
	draw(){
			hgl.glBegin(hgl.GL_POLYGON());
		    const children = this.children || [];
		    children.forEach( i =>  i.draw() );
		  	hgl.glEnd();
	}
};
module.exports = Polygon;
