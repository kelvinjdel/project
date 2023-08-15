var calculateMyAge = function (birthYear) {
    return new Date(Date.now()).getFullYear() - birthYear;
};
var myAge = calculateMyAge(1996);
console.log(myAge);
function greetMe(userInfo) {
    return (userInfo.name + ". its nice to know that you are" + userInfo.age + "years old.");
}
console.log(greetMe({ name: "Kelvin", age: myAge }));
