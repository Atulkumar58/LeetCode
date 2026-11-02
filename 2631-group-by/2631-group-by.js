/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    res= {}
    for(item of this){
        key= fn(item)
        if(key in res) res[key].push(item)
        else res[key]= [item]
        // console.log(item);
    }
    return res
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */