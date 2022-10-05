use std::process::{Command, Stdio};
use std::env;
fn main() {
    let mut scores = json::JsonValue::new_object();
    let mut data = json::JsonValue::new_object();
    let output = Command::new("cargo")
        .arg("run")
        .current_dir(env::current_dir().unwrap().as_path().display().to_string()+"/autograde")
        .stdin(Stdio::null())
        .stdout(Stdio::piped())
        .output();
    match output {
        Ok(o) => {
            let stdout = String::from_utf8(o.stdout).unwrap();
            //very simple check for now, may upgrade to actually do more tests
            if stdout.contains("equal") {
                data["correctness"] = 100.into();
            } else {
                data["correctness"] = 0.into();
            }
        },
        Err(e) => {
            println!("Error in autograding: {:?}", e);
            data["correctness"] = 0.into();
        },
    }
    scores["scores"] = data;
    println!("{}", json::stringify(scores));
}
