use std::fs;

mod generate;
mod pre;
mod parse;

const PROGRAM_PATH: &str = "./res/testprogram.s";


fn main() {
    println!("Compiling!");


    // read code in
    let mut code: String = fs::read_to_string(PROGRAM_PATH)
        .expect("Something went wrong reading in the program");
    // do preprocessing on it
    pre::preprocessing(&mut code);

    // run a lexer on the code
    let statements = parse::parse_code(&code);

    // generate instructions from tokens
    let torch_layout: Vec<String> = generate::generate_binary_torch_layout(&statements);
    for torch_layout_row in torch_layout {
        println!("{}", torch_layout_row);
    }
}   
