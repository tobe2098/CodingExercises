#pragma once
char* shift_args(int* argc, char*** argv) {
	return (*argc)--, * (*argv)++;
}