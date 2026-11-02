/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    return arr.sort((x, y) => fn(x)-fn(y))
    // arr2= [];
    // for(item of arr){
    //     arr2.push([fn(item), item]);
    // }
    // arr2.sort()
    // res=[]
    // for(item of arr2){
    //     console.log(item[0])
    //     res.push(item[1])
    // }
    // return res
};