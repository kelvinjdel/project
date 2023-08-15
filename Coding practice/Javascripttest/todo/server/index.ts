import express from 'express';

const app = express();
app.get('/', (req, res) => {
    res.send('<h1>Hello world!</h1>');
});
// create a server
//listen to some port
app.listen(8000, () => {
    console.log("listening"); //
})