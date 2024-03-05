const obj = {
 a: 1,
 b: [2, 3],
 c: {
   d: 4,
   e: [5, 6],
   f: {
       g: 7
      }
  }
};

const flatten = (obj) =>{
    let result = {};
    
    for(const i in obj){
        
        if(typeof obj[i] === "object" && !Array.isArray(obj[i])){
            
            const temp = flatten(obj[i])
            
            for(const j in temp){
                result[i +"." + j]= temp[j] 
            }
        }
        else if(Array.isArray(obj[i])){
            const flat = obj[i].reduce((acc,item,index)=>{
                result[`${i}.${index}`]= item
                return result
            },{})
        result = {...result, ...flat}
            
        }
        else{
            result[i]= obj[i] 
        }
    }
    return result
}

console.log(flatten(obj))
