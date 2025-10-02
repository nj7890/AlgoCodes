def min_refueling_stops(X, fuel):
    # Sort the fuel list in descending order
    fuel.sort(reverse=True)

    surplus = 0
    refuel_count = 0

    for f in fuel:
        diff = f - X
        surplus += diff

        if surplus < 0:
            # Need to refuel this vehicle
            refuel_count += 1
            surplus = 0  # Reset surplus after refueling

    return refuel_count

# Test input
X = 100
fuel = [80, 120, 90, 100]

result = min_refueling_stops(X, fuel)
print(f"Refuelings needed: {result}")  # Expected: 5
