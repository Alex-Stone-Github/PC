extern crate regex;
use regex::Regex;

pub fn preprocessing(code: &mut String) {
    let oneline_comment_pattern = Regex::new(r"//[\w\s\*/\\!@#$%^&\(\)]*\n").unwrap();
    let muliline_comment_pattern = Regex::new(r"/\*[\w\s\*/\\;@]*\*/!@#$%^&\(\)").unwrap();
    *code = oneline_comment_pattern.replace_all(code, "").into();
    *code = muliline_comment_pattern.replace_all(code, "").into();
    *code = code.replace("\n", "")
}
