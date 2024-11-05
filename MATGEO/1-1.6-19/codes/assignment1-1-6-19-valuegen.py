import sympy as sp
λ = sp.symbols('λ')

A = sp.Matrix([[λ, 1, 2], [1, λ, -1], [2, -1, λ]])
det_A = A.det()

lambda_solutions = sp.solve(det_A, λ)
numeric_solutions = [sp.N(sol) for sol in lambda_solutions]

# Print the numeric solutions using numpy's sqrt function format
formatted_solutions = []
for sol in numeric_solutions:
    formatted_sol = str(sol).replace('sqrt', 'np.sqrt')
    formatted_solutions.append(formatted_sol)


filename = "lambda.dat"
with open(filename, "w") as file:
    for root in formatted_solutions:
        file.write(f"{root}\t")

print(f"Roots have been saved to {filename}.")
