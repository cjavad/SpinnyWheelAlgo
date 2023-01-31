use std::io::{prelude::*, stdin};
use std::str::FromStr;

fn main() {
    let mut data = String::new();
    let input = stdin().read_to_string(&mut data);

    let mut numbers: Vec<_> = data
        .split_whitespace()
        .map(|s| usize::from_str(s).unwrap())
        .collect();

    let count = numbers[0];
    let dep_count = numbers[1]; // ignore thing

    let mut cache = vec![None; count + 1];
    let mut deps = vec![Vec::new(); count + 1];

    for values in numbers[2..].chunks_exact(2) {
        deps[values[0]].push(values[1]);
    }

    let mut max_depth = 1;

    for i in 1..=count {
        max_depth = max_depth.max(get_depth(&deps, &mut cache, i));
    }

    println!("{}", max_depth);
}

fn get_depth(deps: &[Vec<usize>], cache: &mut [Option<usize>], index: usize) -> usize {
    if let Some(depth) = cache[index] {
        return depth;
    }

    let mut max = 0;

    for &i in &deps[index] {
        max = max.max(get_depth(deps, cache, i));
    }

    cache[index] = Some(max + 1);
    return max + 1;
}