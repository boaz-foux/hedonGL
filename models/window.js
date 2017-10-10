const hgl =require('./hgl'),
	  Input = require('./input'),
	  privates = new WeakMap();

module.exports = Window;

let counter = 0;
class Window {
	destroy(){
		counter--;
		hgl.glfwTerminate();
	}
	draw(){
		const
			begin = Date.now(), 
			{ settings , window , children } = privates.get(this),
			scale = 10,
			ratio = scale*settings.width/settings.height;

		hgl.glViewport(
		  0,
		  0,
		  settings.width,
		  settings.height);
		hgl.glMatrixMode(hgl.GL_PROJECTION());
		hgl.glLoadIdentity();

		/* TODO :  add view controller model initialized with the input model*/
		const viewer = [0.0 ,1.0 ,4.0 ],
				eyes = [0.0, 0.0, 0.0],
				normal = [0.0 ,1.0,0.0];
				// framebuffer = settings.render.framebuffer || {};
		hgl.glOrtho(-ratio, ratio , -1.0*scale, 1.0*scale, 1.0*scale, -1.0*scale);
		hgl.gluLookAt(...viewer,...eyes,...normal);
 		hgl.gluPerspective(45, 4.0/3, 0.1, 2);
 		// hgl.glClearDepth(1.0);
		

		hgl.glMatrixMode(hgl.GL_MODELVIEW());
		hgl.glClear(hgl.GL_COLOR_BUFFER_BIT() | hgl.GL_DEPTH_BUFFER_BIT());
		hgl.glClearColor (0.0,0.0,0.0,1.0);
		hgl.glLoadIdentity();
		

		children.forEach( i =>  i.draw() );
		const rednderTime = Date.now() - begin;
		hgl.glfwSwapBuffers(window);
		hgl.glfwPollEvents();
		if(hgl.glfwGetKey(window, hgl.GLFW_KEY_ESCAPE() ) != hgl.GLFW_PRESS() &&
		hgl.glfwWindowShouldClose(window) == 0){
			setTimeout(this.draw.bind(this),1);
		}
		else {
			this.destroy();
		}

	}
	constructor(settings = {} ,children = []) {
		info = {};
		settings.width = ( settings.width && settings.width > 0 )  || 1024;
	 	settings.height = ( settings.height && settings.height > 0 )  || 768;
	 	settings.title = settings.title|| "untitled";
	 	settings.location = { x: null , y:null };
	 	if( !hgl.glfwInit() ){
				throw "Failed to initialize GLFW\n" ;
			}
		// hgl.glfwWindowHint(hgl.GLFW_DECORATED(), 0);
		const window =  hgl.CreateWindow(settings.width,settings.height,settings.title);
		// hgl.glfwSetInputMode(window, hgl.GLFW_CURSOR, hgl.GLFW_CURSOR_HIDDEN());		
		hgl.glfwSetInputMode(window, hgl.GLFW_STICKY_KEYS(), hgl.GL_TRUE());
		hgl.glfwMakeContextCurrent(window); 
		if (hgl.glewInit() != hgl.GLEW_OK()) {
			throw "Failed to initialize GLEW\n";
			}
		hgl.glEnable(hgl.GL_DEPTH_TEST()); // not working when looking from negative z index
		hgl.glDepthFunc(hgl.GL_LEQUAL());
		settings.isOpen = true;
		settings.render ={
			last: 0,
			request: Date.now(),
			framebuffer :{ size : null }
		};
		settings.focus = false;
		hgl.glfwSetWindowPosCallback( window,
			(win,x,y) => {
				if(window != win) {
					return;
				}
				settings.location.x = x;
				settings.location.y = y;
			});
		hgl.glfwSetWindowSizeCallback( window,
			(win,width,height) => {
				if(window != win) {
					return;
				}
					settings.width = width;
					settings.height = height; 
			});
		hgl.glfwSetWindowCloseCallback( window,
			(win) => {
				if(window != win) {
					return;
				}
				settings.isOpen = false;
			});
		hgl.glfwSetWindowRefreshCallback( window,
			(win,r) => {
				if(window != win) {
					return;
				}
				settings.render.request = Date.now();
			});
		hgl.glfwSetWindowFocusCallback( window,
			(win,focus) => {
				if(window != win) {
					return;
				}
				settings.focus = focus; 
			});
		hgl.glfwSetFramebufferSizeCallback( window,
			(win,size_x,size_y) => {
				if(window != win) {
					return;
				}
				settings.width = size_x;
				settings.height = size_y;

			});
		const input = new Input(window);
		privates.set(this,{input , window  settings , children });
 		counter++;
 		
		this.draw();

		//HDMI PATCH! :'(
		hgl.GetFramebufferSize(window,(w,h)=>{
			settings.width  = w;
			settings.height = h;
		});
	}

};





