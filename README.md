# hedonGL
a simple POC for hedonh,
hedongl invoke the functionality of gl glu & glfw to node.js .

for example:
```js
const hgl =require('hedonGL'),
 	x =1024,
 	y =  768,
 	title= "title name",
 	draw = ()=>{
		hgl.glBegin(hgl.GL_POLYGON());
	    hgl.glColor3f(1, 0, 0); hgl.glVertex3f(-0.6, -0.75, 0);
	    hgl.glColor3f(0, 1, 0); hgl.glVertex3f(0.6, -0.75, 0);
	    hgl.glColor3f(0, 0, 1); hgl.glVertex3f(0, 0.75, 0);
	  	hgl.glEnd();
	};

if( !hgl.glfwInit() ){
	return console.log( "Failed to initialize GLFW\n" );
}
/*
	patch for an error on -> hgl.glfwCreateWindow(x,y,title,0,0);
*/
const window = hgl.CreateWindow(x,y,title);  

hgl.glfwSetInputMode(window, hgl.GLFW_STICKY_KEYS(), hgl.GL_TRUE());

hgl.glfwMakeContextCurrent(window); // Initialize GLEW

if (hgl.glewInit() != hgl.GLEW_OK()) {
	return console.log( "Failed to initialize GLEW\n");
}

hgl.glEnable(hgl.GL_DEPTH_TEST());

const render = () =>{
	hgl.glMatrixMode(hgl.GL_PROJECTION());
	hgl.glLoadIdentity();
	// hgl.glOrtho(-(x/y), x/y , -1.0, 1.0, 1.0, -1.0);
	hgl.glClear(hgl.GL_COLOR_BUFFER_BIT() | hgl.GL_DEPTH_BUFFER_BIT());
	hgl.gluLookAt(0.0, 0.0, -1.0,  /* eye is at -where i stand */
	   0.0, 0.0, 1.1,      /* center is at - where do i look */
	   0.0, 1.0, 0.0);     /* up is in positive - normal */

	hgl.glMatrixMode(hgl.GL_MODELVIEW());
	hgl.glLoadIdentity();
	draw();
	hgl.glfwSwapBuffers(window);
	hgl.glfwPollEvents();
	if(hgl.glfwGetKey(window, hgl.GLFW_KEY_ESCAPE() ) != hgl.GLFW_PRESS() &&
	hgl.glfwWindowShouldClose(window) == 0){
		setTimeout(render,1);
	}
	else {
		hgl.glfwTerminate();
	}

};
hgl.glfwSetWindowPosCallback( window, (win,x,y) => {
		console.log('windowPosCB' ,x,y ); 
	});
hgl.glfwSetWindowSizeCallback( window, (win,dx,dy) => {
		console.log('windowSizeCB' , dx,dy); 
	});
hgl.glfwSetWindowCloseCallback( window, (win,v) => {
		console.log('windowCloseCB ' ,v ); 
	});
hgl.glfwSetWindowRefreshCallback( window, (win,r) => {
		console.log('windowRefreshCB' , r); 
	});
hgl.glfwSetWindowFocusCallback( window, (win,focus) => {
		 console.log('windowFocusCB' , focus); 
	});
hgl.glfwSetWindowIconifyCallback( window, (win,i) => {
		console.log('windowIconifyCB' , i); 
	});
hgl.glfwSetFramebufferSizeCallback( window, (win,size) => {
		console.log('windowFramebufferSizeCB' , size); 
	});
hgl.glfwSetKeyCallback( window, (win , key,x,y) => {
		console.log('keyCB' , key,x,y); 
	});
hgl.glfwSetMouseButtonCallback( window, (win,click,isRight) => {
		console.log('mouseButtonCB' , click,isRight); 
	});
hgl.glfwSetCursorPosCallback( window, (win,x,y) => {
		console.log('cursorPosCB' , x,y); 
	});
hgl.glfwSetCursorEnterCallback( window, (win,isIn) => {
		console.log('cursorEnterCB' , !!isIn ? 'in' :  'out'); 
	});
hgl.glfwSetScrollCallback( window, (win, yaxis,xaxis) => {
		console.log('scrollCB' ,yaxis,xaxis ); 
	});
	

setTimeout(render,1);
```