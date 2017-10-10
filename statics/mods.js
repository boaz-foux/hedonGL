
const mods = [{
	label:'ALT',
	value: 0x0004 
},
{
	label:'CONTROL',
	value: 0x0002 
},
{
	label:'SHIFT',
	value: 0x0001 
},
{
	label:'SUPER',
	value: 0x0008 
}];

module.exports = {
	getMods: mod => mods.filter( _mod => _mod.value & mod  ).map( _mod => _mod.label )
};