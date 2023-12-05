package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	fibN := fib(n)
	fmt.Printf("%d\n", fibN)
}
