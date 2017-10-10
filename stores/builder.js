const { createStore , combineReducers , applyMiddleware} = require('redux');
	
module.exports = ({ middlewares = [] , reducers = {} } = {}) => {
	const stores = new WeakMap();
	return self => {
		let store  = stores.get(self);
		if(store) {
			return store;
		}
		store = createStore( combine(reducers),flatAndApply(middlewares));
		stores.set(self,store);
		return store; 
	};
};

function combine(obj ={}){
	if(obj instanceof Function){ 
		return obj; 
	}
	for(var i in obj){
		obj[i] =  combine(obj[i]);
	}
	return combineReducers(obj);
};



function flatAndApply(array = []) {
  array = Array.isArray(array) ? array : [array]
  return applyMiddleware(
	  array.reduce(
	  	(flat, toFlatten) => flat.concat( 
	  		Array.isArray(toFlatten) ? flatten(toFlatten) : toFlatten
	  		)
	    , [])
	  );
}