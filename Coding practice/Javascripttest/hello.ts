type user= {
    name: string,
    age: number,
    isMarried: boolean,
    hobbies: string[];
    gender?: string;
};

const user: user={

    name: 'Kelvin',
    age: 27,
    isMarried: false,
    hobbies: ["Playing soccer","Pogging"],
};


const users:{
    name: string;
    age: number;
    isMarried: boolean;
    hobbies: string[];
}[]= [user];