use crate::parse::{Statement, ReadOrWriteNode, Setting};

const NUM_OF_CONTROL_LINES: usize = 27;

fn u8_to_string_representation(number: u8) -> String {
    let str_representation: String = format!("{:b}", number);
    let mut padding = String::new();
    // this code is disgusting, but at least I know its bad
    for _i in 0..(8-str_representation.len()) {
        padding.push('0');
    }
    padding.push_str(&str_representation);
    padding
}

pub fn generate_binary_torch_layout(statements: &Vec<Statement>) -> Vec<String> {
    let mut torch_layout: Vec<String> = Vec::new();
    let instruction_statments: Vec<Vec<Statement>> = statements.split(|x| *x == Statement::Step).filter(|x| !x.is_empty()).map(|x| x.into()).collect();
    for (i, instruction_statement) in instruction_statments.iter().enumerate() {
        torch_layout.push(String::new());
        if instruction_statement.contains(&Statement::If) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::Address)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::InstructionCounter)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::D)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::D)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::C)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::C)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::B)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::B)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::A)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::A)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::InputOutputBus)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::InputOutputBus)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::Ram)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::Ram)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Read(ReadOrWriteNode::Processor)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Set(Setting::DoSubtraction)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::ProcessorB)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        if instruction_statement.contains(&Statement::Write(ReadOrWriteNode::ProcessorA)) {
            torch_layout[i].push('1');
        } else {
            torch_layout[i].push('0');
        }
        for statement in instruction_statement.iter() {
            let mut found_put: bool = false;
            match statement {
                Statement::Put(x) => {
                    found_put = true;
                    torch_layout[i].push_str(&u8_to_string_representation(*x));
                },
                _ => {}
            }
        }
    }
    //assert_eq!(NUM_OF_CONTROL_LINES, torch_layout[0].len());
    torch_layout
}
