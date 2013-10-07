#!/usr/bin/env node

function make_pair(x, y) {
    return {
        get_left : function() { return x },
        get_right : function() { return y }
    }
}

function get_left(pair) {
    return pair.get_left();
}

function get_right(pair) {
    return pair.get_right();
}

// Test case
console.log(get_left(make_pair(1, 2))) // 1
console.log(get_right(make_pair(1, 2))) // 2
