Note Object.entries are used on objects and map, forEach, reduce are used on array
If you want to use the array methods on objects then destructure it by using Object.entries first.

suppose obj = {a : [1,2], b : [1,2]}
Op should be { 'a.0': 1, 'a.1': 2, 'b.0': 1, 'b.1': 2 }
let result = {};
Object.entries(obj).forEach(([key,value])=>{
        value.forEach((item, index)=>{
        result[`${key}.${index}`]=item
        })
})
In this we don't know yet the value is array or not, so we destructure first and then on value apply forEach.

In cases like where obj[key] is provided

obj[i].forEach((item, index))=>{
result[`${i}.${index}`]=item;
})

or

obj[i].reduce((acc, item, index)=>{
result[`${i}.${index}`]=item;    
}, {})
