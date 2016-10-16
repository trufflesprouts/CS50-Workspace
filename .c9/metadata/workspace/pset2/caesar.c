{"filter":false,"title":"caesar.c","tooltip":"/pset2/caesar.c","undoManager":{"mark":3,"position":-1,"stack":[[{"start":{"row":52,"column":0},"end":{"row":80,"column":0},"action":"insert","lines":["var indexOfMinimum = function(array, startIndex) {","    // Set initial values for minValue and minIndex,","    // based on the leftmost entry in the subarray:  ","    var minValue = array[startIndex];","    var minIndex = startIndex;","    ","    for (var t = minIndex + 1; t < array.lenght; t++) {","        if (array[t] < minValue) {","            minIndex = t;","            minValue = array[t];","        }","    }","    // Loop over items starting with startIndex, ","    // updating minValue and minIndex as needed:","    ","    return minIndex;","}; ","","var array = [18, 6, 66, 44, 9, 22, 14];   ","var index = indexOfMinimum(array, 2);","","//  For the test array [18, 6, 66, 44, 9, 22, 14], ","//  the value 9 is the smallest of [..66, 44, 9, 22, 14]","//  Since 9 is at index 4 in the original array, ","//  \"index\" has value 4","println(\"The index of the minimum value of the subarray starting at index 2 is \" + index + \".\"  );","Program.assertEqual(index, 4);","",""],"id":658}],[{"start":{"row":51,"column":0},"end":{"row":52,"column":0},"action":"insert","lines":["",""],"id":659}],[{"start":{"row":50,"column":0},"end":{"row":51,"column":0},"action":"insert","lines":["",""],"id":660}],[{"start":{"row":49,"column":1},"end":{"row":50,"column":0},"action":"insert","lines":["",""],"id":661}]]},"ace":{"folds":[],"scrolltop":0,"scrollleft":0,"selection":{"start":{"row":18,"column":4},"end":{"row":18,"column":4},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":0},"timestamp":1452615748000,"hash":"b785bd21d32dd8011d5f717f924ecc43602b5095"}