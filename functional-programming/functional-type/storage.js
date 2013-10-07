#!/usr/bin/env node

// Type Storage
function deposit(data) {
    var _key = _generate_key() 

    return function() {
        return {
            key : _key,
            withdraw : function (key) {
                return key == _key ? data : null
            }
        }
    }
}

function key(storage) {
    return storage().key
}

function withdraw(storage, key) {
    return storage().withdraw(key)
}

// private 
var _key_num = 0

function _generate_key() {
    return ++_key_num
}

// test case
var todd_storage = deposit("todd's wallet")
var todd_key = key(todd_storage)

var april_storage = deposit("april's handbag")
var april_key = key(april_storage)

var data = withdraw(todd_storage, april_key)
console.log(data) // null

data = withdraw(april_storage, todd_key)
console.log(data) // null

data = withdraw(todd_storage, todd_key)
console.log(data) // "todd's wallet"

data = withdraw(april_storage, april_key)
console.log(data) // "april's handbag"
