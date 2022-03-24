use crate::parse::{Statement};

const NUM_OF_CONTROL_LINES: i32 = 28;

pub fn generate_binary_torch_layout(statements: &Vec<Statement>) {
    let torch_layout: Vec<String>;


    let instruction_statments: Vec<Vec<Statement>> = statements.split(|x| *x == Statement::Step).filter(|x| !x.is_empty()).map(|x| x.into()).collect();
    for instruction_statement in instruction_statments.iter() {
        //
    }
}