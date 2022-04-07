#[derive(Debug, Clone, PartialEq)]
pub enum ReadOrWriteNode {
    A,
    B,
    C,
    D,
    ProcessorA,
    ProcessorB,
    Processor,
    InputOutputBus,
    Ram,
    Address,
    InstructionCounter
}
#[derive(Debug, Clone, PartialEq)]
pub enum Setting {
    DoSubtraction
}
#[derive(Debug, Clone, PartialEq)]
pub enum Statement {
    If,
    Set(Setting),
    Put(u8),
    Write(ReadOrWriteNode),
    Read(ReadOrWriteNode),
    Step,

}

impl ReadOrWriteNode {
    fn from_str(expression: &str) -> Self{
        match expression {
            "a" => ReadOrWriteNode::A,
            "b" => ReadOrWriteNode::B,
            "c" => ReadOrWriteNode::C,
            "d" => ReadOrWriteNode::D,
            "processor_a" => ReadOrWriteNode::ProcessorA,
            "processor_b" => ReadOrWriteNode::ProcessorB,
            "processor" => ReadOrWriteNode::Processor,
            "address" => ReadOrWriteNode::Address,
            "instruction_counter" => ReadOrWriteNode::InstructionCounter,
            "io" => ReadOrWriteNode::InputOutputBus,
            "ram" => ReadOrWriteNode::Ram,
            _ => {panic!("Failed to convert {} to a ReadOrWriteNode", expression)}
        }
    }
}


pub fn parse_code(code: &String) -> Vec<Statement> {
    let statement_strings: Vec<String> = code.split(';').filter(|x| x.len() > 1).map(|x| x.into()).collect();
    let mut statements: Vec<Statement> = vec![];
    for statement_string in statement_strings.iter() {
        let expressions: Vec<&str> = statement_string.split(' ').filter(|x| x.len() != 0).collect();
        println!("{:?}", expressions);
        if expressions.len() > 2 {
            panic!("Expression is too long!");
        }
        let statement: Statement = match expressions[0] {
            "if" => Statement::If,
            "read" => Statement::Read(ReadOrWriteNode::from_str(expressions[1])),
            "write" => Statement::Write(ReadOrWriteNode::from_str(expressions[1])),
            "put" => Statement::Put(expressions[1].parse().expect("Expressions must be a number")),
            "step" => Statement::Step,
            "set" => Statement::Set(match expressions[1] {
                "sub" => Setting::DoSubtraction,
                _ => {panic!("Not a valid setting");}
            }),
            _ => {panic!("This is not a valid statement");}
        };
        statements.push(statement);
    }
    statements
}
