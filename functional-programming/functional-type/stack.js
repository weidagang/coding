#!/usr/bin/env node

function make_stack() {
    return null
}

function push(stack, x) {
    return {
        top : function() { return x },
        pop : function() { return stack }
    }
}

function top(stack) {
    return stack.top()
}

function pop(stack) {
    return stack.pop()
}


// Test case
var stack = make_stack()
stack = push(stack, 1)
stack = push(stack, 2)
stack = push(stack, 3)
console.log(top(stack)) // 3
stack = pop(stack)
console.log(top(stack)) // 2
stack = push(stack, 4)
console.log(top(stack)) // 4
