const builder = require('../build'),
	middlewares =  require('./middlewares'),
	reducers =  require('./reducers');

	
module.exports = builder({ middlewares, reducers });