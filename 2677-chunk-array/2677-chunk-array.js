/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    result=[];
    while(arr.length > 0){
        // console.log (arr.length);
        // console.log(arr);
        result.push(arr.splice(0, size));
        // console.log(arr);
    }
    return result;
};
