#!/usr/bin/env node

function empty() {
    return null
}

function singleton(e) {
    return {
        first : function() { return e },
        rest : function() { return null }
    }
}

function first(list) {
    return list.first()
}

function rest(list) {
    return list.rest()
}

function append(list1, list2) {
    if (null == list1) return list2
    if (null == list2) return list1

    return {
        first : function() { return first(list1) }, 
        rest : function() { return append(rest(list1), list2) }
    }
}

function make_binary_tree_iterator(node) {
    return {
        first : function() {
            return  null != node.left ? first(make_binary_tree_iterator(node.left)) : node
        },
        rest : function() {
            var left_it = (null == node.left ? null : make_binary_tree_iterator(node.left))
            var root_it = singleton(node)
            var right_it = (null == node.right ? null : make_binary_tree_iterator(node.right))

            var it = append(append(left_it, root_it), right_it)

            return rest(it)
        }
    }
}

//======== Test case ========
var tree = { 
    value : 1, 
    left : {
        value : 2,
        left : {
            value : 4,
            left : null,
            right : null
        },
        right : null
    },
    right : {
        value : 3,
        left : null,
        right : {
            value : 7,
            left : null,
            right : null
        }
    }
}

for (var it = make_binary_tree_iterator(tree); null != it; it = rest(it)) {
    console.log(first(it).value)
}
