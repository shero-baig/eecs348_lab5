def input_file_read(file):
    try:
        with open(file, 'r') as file:
            data_input_file = [float(line) for line in file.readlines()]
        return data_input_file
    except FileNotFoundError:
        print(f"File not found: {file}")
        return []


def monthly_sales(data_input):
    months = [
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    ]
    print("Monthly sales report for 2022:")
    print("Month    Sales")
    for money, month in enumerate(months):
        print(f"{month} ${data_input[money]:.2f}")


def sales_summary(data):
    minimum_sale_monthly = min(data)
    maximum_sale_monthly = max(data)
    average_sale_monthly = sum(data) / len(data)

    print("\nSales summary:")
    print(f"Minimum sales: ${minimum_sale_monthly:.2f} (January)")
    print(f"Maximum sales: ${maximum_sale_monthly:.2f} (December)")
    print(f"Average sales: ${average_sale_monthly:.2f}")


def six_month_moving_average_report(data):
    months = [
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    ]

    print("\nSix-Month Moving Average Report:")
    for money in range(6, len(data)):
        average_money = sum(data[money - 6:money]) / 6
        print(f"{months[money - 6]} - {months[money]} ${average_money:.2f}")


def highest_to_lowest_sales(data):
    months = [
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    ]
    month_sales = list(zip(months, data))
    month_sales.sort(key=lambda x: x[1], reverse=True)

    print("\nSales Report (Highest to Lowest):")
    print("Month    Sales")
    for month, sale in month_sales:
        print(f"{month} ${sale:.2f}")


if __name__ == "__main__":
    input_file = "sales_data.txt"  # Replace with your input file path
    sales_data = input_file_read(input_file)

    if sales_data:
        monthly_sales(sales_data)
        sales_summary(sales_data)
        six_month_moving_average_report(sales_data)
        highest_to_lowest_sales(sales_data)

