// ***O(logn) - Binary search***

// let arr = [];
// for (let i = 1; i <= 100; i++) {
//   arr.push(i);
// }
// let start = 0;
// let end = arr.length - 1;
// let target = 10;

// function binarySearch(arr, start, end, target) {
//   console.log(arr.slice(start, end));

//   if (start > end) return false;
//   let midIndex = Math.floor((start + end) / 2);
//   if (arr[midIndex] === target) return true;

//   if (arr[midIndex] > target)
//     return binarySearch(arr, start, midIndex - 1, target);
//   else return binarySearch(arr, midIndex + 1, end, target);
// }

// console.log(binarySearch(arr, start, end, target));

// ***O(logn) - Binary search***

// ***O(n logn)***

// function nLogNFunc(n) {
//   let y = n;

//   while (n > 1) {
//     n = Math.floor(n / 2);
//     for (let i = 0; i < y; i++) {
//       console.log(i);
//     }
//   }
// }

// nLogNFunc(4);

// function mergeSort(arr) {
//   // O(logn)
//   if (arr.length < 2) {
//     return arr;
//   }

//   const middleIndex = Math.floor(arr.length / 2);
//   const leftArr = arr.slice(0, middleIndex);
//   const rightArr = arr.slice(middleIndex, arr.length);

//   return merge(mergeSort(leftArr), mergeSort(rightArr)); // O(n)
// }

// // O(Nlogn)
// function merge(leftArr, rightArr) {
//   let result = [];
//   let leftIndex = 0;
//   let rightIndex = 0;

//   while (leftIndex < leftArr.length && rightIndex < rightArr.length) {
//     if (leftArr[leftIndex] < rightArr[rightIndex]) {
//       result.push(leftArr[leftIndex]);
//       leftIndex += 1;
//     } else {
//       result.push(rightArr[rightIndex]);
//       rightIndex += 1;
//     }
//   }
//   return result
//     .concat(leftArr.slice(leftIndex))
//     .concat(rightArr.slice(rightIndex));
// }

// let arr = [2, 1, 24, 5, 1, 13, 56, 476, 7, 7];
// console.log(mergeSort(arr));
// console.log(merge([18, 9, 10], [13, 56, 476]));
// ***O(n logn)***

//O(2^n) fibonacci

// function fibonacci(n) {
//   if (n <= 1) return n;
//   return fibonacci(n - 1) + fibonacci(n - 2);
// }

// console.log(fibonacci(10));

//O(2^n) fibonacci

// O(n!)

// function func(n) {
//   if (n === 0) {
//     console.log('**********');
//     return;
//   }
//   for (let i = 0; i < n; i++) {
//     func(n - 1);
//   }
// }

// func(2);

// O(n!)

// let arr = [p1, p2, p3, p4];

// function weeks(p1, p2, p3, p4) {
//   let arr = [p1, p2, p3, p4];
//   let sum = 0;
//   for (let i = 0; i < arr.length; i++) {
//     if (arr[i] >= 10) {
//       sum += 1;
//     }
//   }
//   return sum;

// arr.map((ar) => {
//   if (ar < 10) {
//     let remarr = arr.indexOf(ar);

//     arr.splice(remarr, 1);
//   }
// });
// return arr.length;
// }

// console.log(weeks(2, 10, 14, 11));

// function checkVowel(n) {
//   let al = ['A', 'E', 'I', 'O', 'U'];
//   // let arr = al.split('');
//   for (let i = 0; i < al.length; i++) {
//     if (al[i] === n) {
//       return 'Vowel';
//     } else {
//       return 'Consonant';
//     }
//   }
// }

// console.log(checkVowel('Z'));

// function sortArray(a = [], n) {
//   if (n === 1) {
//     return 1;
//   } else {
//     // let arr = sortArray(n - 1);
//     // arr.push(n);
//     // return n - 1 < n - 2 ? 0 : arr;
//     for (let i = 0; i < n; i++) {
//       if (a[i] > a[i + 1]) {
//         let temp = a[i];
//         a[i] = a[i + 1];
//         a[i + 1] = temp;
//         return temp;
//       }
//     }
//   }
// }

// console.log(sortArray([1, 23, 34, 2, 34, 65, 4]));

// sortin array

// function mergeSort(arr) {
//   // O(logn)
//   if (arr.length < 2) {
//     return arr;
//   }

//   const middleIndex = Math.floor(arr.length / 2);
//   const leftArr = arr.slice(0, middleIndex);
//   const rightArr = arr.slice(middleIndex, arr.length);

//   return merge(mergeSort(leftArr), mergeSort(rightArr)); // O(n)
// }

// function merge(leftArr, rightArr) {
//   let result = [];
//   let leftIndex = 0;
//   let rightIndex = 0;

//   while (leftIndex < leftArr.length && rightIndex < rightArr.length) {
//     if (leftArr[leftIndex] < rightArr[rightIndex]) {
//       result.push(leftArr[leftIndex]);
//       leftIndex += 1;
//     } else {
//       result.push(rightArr[rightIndex]);
//       rightIndex += 1;
//     }
//   }
//   return result
//     .concat(leftArr.slice(leftIndex))
//     .concat(rightArr.slice(rightIndex));
// }

// let arr = [2, 1, 24, 5, 1, 13, 56, 476, 7, 7];
// // console.log(mergeSort(arr));

// Array.prototype.merge_Sort = function () {
//   if (this.length <= 1) {
//     return this;
//   }

//   let half = parseInt(this.length / 2);
//   let left = this.slice(0, half).merge_Sort();
//   let right = this.slice(half, this.length).merge_Sort();
//   let merge = function (left, right) {
//     let arry = [];
//     while (left.length > 0 && right.length > 0) {
//       arry.push(left[0] <= right[0] ? left.shift() : right.shift());
//     }
//     return arry.concat(left).concat(right);
//   };

//   return merge(left, right);
// };

// let a = [34, 7, 23, 32, 5, 62];
// console.log(a.merge_Sort());

// function noname(n) {
//   let sum = 0;

//   for (let i = 0; i * i < n; i++) {
//     sum++;
//     // console.log(i);
//   }
//   return sum;
// }

// console.log(noname(15));

// function noname(n) {
//   let i,
//     j,
//     k,
//     count = 0;

//   for (i = n / 2; i <= n; i++) {
//     for (j = 1; j + n / 2 <= n; j++) {
//       for (k = 1; k <= n; k *= 2) {
//         count++;
//       }
//     }
//   }
//   return count;
// }

// console.log(noname(5));

// let ab = 5;
// let bc = 2;
// console.log(ab / bc);

// Backtracking

// let N = 4;

// /* ld is an array where its indices indicate row-col+N-1
// (N-1) is for shifting the difference to store negative
// indices */
// let ld = new Array(30);
// // console.log(ld);

// /* rd is an array where its indices indicate row+col
// and used to check whether a queen can be placed on
// right diagonal or not*/
// let rd = new Array(30);

// /*column array where its indices indicates column and
// used to check whether a queen can be placed in that
//     row or not*/
// let cl = new Array(30);

// /* A utility function to print solution */
// function printSolution(board) {
//   for (let i = 0; i < N; i++) {
//     for (let j = 0; j < N; j++) console.log(board[i][j] + ' ');
//     console.log('<br/>');
//   }
// }

// /* A recursive utility function to solve N
// Queen problem */
// function solveNQUtil(board, col) {
//   /* base case: If all queens are placed
//     then return true */
//   if (col >= N) return true;

//   /* Consider this column and try placing
//     this queen in all rows one by one */
//   for (let i = 0; i < N; i++) {
//     /* Check if the queen can be placed on
//         board[i][col] */
//     /* A check if a queen can be placed on
//         board[row][col].We just need to check
//         ld[row-col+n-1] and rd[row+coln] where
//         ld and rd are for left and right
//         diagonal respectively*/
//     if (ld[i - col + N - 1] != 1 && rd[i + col] != 1 && cl[i] != 1) {
//       /* Place this queen in board[i][col] */
//       board[i][col] = 1;
//       ld[i - col + N - 1] = rd[i + col] = cl[i] = 1;

//       /* recur to place rest of the queens */
//       if (solveNQUtil(board, col + 1)) return true;

//       /* If placing queen in board[i][col]
//             doesn't lead to a solution, then
//             remove queen from board[i][col] */
//       board[i][col] = 0; // BACKTRACK
//       ld[i - col + N - 1] = rd[i + col] = cl[i] = 0;
//     }
//   }

//   /* If the queen cannot be placed in any row in
//         this column col then return false */
//   return false;
// }
// /* This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one of the
// feasible solutions.*/
// function solveNQ() {
//   let board = [
//     [0, 0, 0, 0],
//     [0, 0, 0, 0],
//     [0, 0, 0, 0],
//     [0, 0, 0, 0],
//   ];

//   if (solveNQUtil(board, 0) == false) {
//     console.log('Solution does not exist');
//     return false;
//   }

//   printSolution(board);
//   return true;
// }

// // Driver code

// solveNQ();

//Backtracking

//Linked list

// Nested loop

// function loop(s) {
//   let i, j;
//   for (i = 0; i < s.length; i++) {
//     for (j = i; j < s.length; j++) {
//       for (let k = 0; k < (j - i + 1) / 2; k++)
//         // if (s[i + k] != s[j - k]) flag = 0;
//         // console.log(i + k);
//         // console.log(s[i + k]);
//         console.log(s[j - k]);
// let flag = 1;
// for (let k = 0; k < (j - i + 1) / 2; k++)
//         if (s[i + k] != s[j - k])
//             flag = 0;
//     // Palindrome
//     if (flag!=0 && (j - i + 1) > maxLength) {
//         start = i;
//         maxLength = j - i + 1;
// }
// console.log((j - i + 1) / 2); // 1/2 is the middle of the string
// console.log('Breaking point');
// console.log(j - i + 1);
// console.log('Breaking point');
// console.log(j - i);
// console.log('Breaking point');
// console.log(i);
// console.log('Breaking point');
// console.log(j);
//   }
// }

// loop('geeksforgeeks');

// palindrom check

function solution(x) {
  // let res = [];
  let res =
    parseFloat(x.toString().split('').reverse().join('')) * Math.sign(x);
  if (res === x) {
    return true;
  } else {
    return false;
  }
}

console.log(solution(10));

// another way check palindrom

function solutionll(x) {
  let len = x.length;
  if (len < 2) {
    return true;
  }
  let i = 0,
    j = len - 1;
  // console.log(j);
  while (i < j) {
    if (s[i] != s[j]) {
      return false;
    }
    i += 1;
    j -= 1;
  }
  return true;
}

let pal = solutionll(101);
console.log(pal);
