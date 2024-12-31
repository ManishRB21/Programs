const express = require('express');

// custom middleware create
const LoggerMiddleware = (req,res,next) =>{
    console.log(`Logged  ${req.url}  ${req.method} -- ${new Date()}`)
    next();
}

const app = express()

// application level middleware
app.use(LoggerMiddleware);


// users route
app.get('/users',(req,res)=>{
    res.json({
        'status':true
    })
})


// save route
app.post('/save',(req,res)=>{
    res.json({
        'status':true
    })
})

app.listen(3002,(req,res)=>{
    console.log('server running on port 3002')
})
