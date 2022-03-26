use std::fs;

mod generate;
mod pre;
mod parse;

const PROGRAM_PATH: &str = "./res/testprogram.asm";


fn main() {
    // read code in
    let mut code: String = fs::read_to_string(PROGRAM_PATH)
        .expect("Something went wrong reading in the program");
    // do preprocessing on it
    pre::preprocessing(&mut code);
    let statements = parse::parse_code(&code);
    println!("{:?}", statements);
    let torch_layout: Vec<String> = generate::generate_binary_torch_layout(&statements);
    println!("{:?}", torch_layout);
}   
