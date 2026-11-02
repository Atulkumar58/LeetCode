/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    // val= [...obj]
    if(Object.keys(obj).length == 0) return true;
    return false;
};