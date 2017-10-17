const hgl = require('../hgl');
module.exports = ( props  , children = []) => {
			hgl.glBegin(hgl.GL_POLYGON());
		    children.forEach( i =>  i.draw() );
		  	hgl.glEnd();	
};
