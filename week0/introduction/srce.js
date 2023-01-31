/**
 * Input:
 * 1 2
 * 
 * Output:
 * 
 * 3
 */

process.stdin.on('data', function (data) {
    console.log(data.toString().split(' ').map(Number).reduce((a, b) => a + b, 0));
});