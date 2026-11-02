/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const resultMap = new Map();

    // 1. Insert all items from arr1 into the map
    for (const item of arr1) {
        resultMap.set(item.id, { ...item });
    }

    // 2. Merge or insert items from arr2 into the map
    for (const item of arr2) {
        if (resultMap.has(item.id)) {
            // Overwrite existing properties with arr2's values
            Object.assign(resultMap.get(item.id), item);
        } else {
            resultMap.set(item.id, { ...item });
        }
    }

    // 3. Convert map values back to an array and sort by id
    return Array.from(resultMap.values()).sort((a, b) => a.id - b.id);
};
