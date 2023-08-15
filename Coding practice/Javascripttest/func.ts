const calculateMyAge= (birthYear: number): number=>{
    return new Date(Date.now()).getFullYear()-birthYear
}

const myAge: number = calculateMyAge(1996);

console.log(myAge);

function greetMe(userInfo: {name: string; age: number}): string {
    return (
        userInfo.name + ". its nice to know that you are " + userInfo.age + " years old."

    );
}

console.log(greetMe({name: "Kelvin", age: myAge}))
