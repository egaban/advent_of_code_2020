fn main() {
    let mut vetor: Vec<i32> = Vec::new();

    read_input(&mut vetor);

    for i in 0..vetor.len() {
        for j in i + 1..vetor.len() {
            if vetor[i] + vetor[j] == 2020 {
                println!("{}", vetor[i] * vetor[j]);
            }
        }
    }
}

fn read_input(v: &mut Vec<i32>) {
    loop {
        let n = read_int();

        match n {
            Some(x) => v.push(x),
            None => break,
        }
    }
}

fn read_int() -> Option<i32> {
    let mut number = String::new();

    match std::io::stdin().read_line(&mut number) {
        Ok(0) => return None,
        Ok(_) => {
            let number: i32 = number.trim().parse().expect("Failed to parse");
            return Some(number);
        }
        Err(_) => panic!(),
    }
}
