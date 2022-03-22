use std::fs;

const PROGRAM_PATH: &str = "./res/testprogram.asm";


fn preprocessing(code: &mut String) {
    *code = code.replace("write", "out");
}

fn main() {
    let mut code: String = fs::read_to_string(PROGRAM_PATH)
        .expect("Something went wrong reading in the program");
    println!("{}", code);
    preprocessing(&mut code);
    println!("{}", code);
}   
