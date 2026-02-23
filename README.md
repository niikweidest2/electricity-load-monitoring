# Electrical Load Monitoring & Billing System

A simple C++ console-based application to manage household appliances, calculate daily electricity usage, and estimate electricity billing costs.

---

## Features

- Register new appliances (name, watts, hours per day)
- View all registered appliances
- Search appliances by name
- Calculate total daily electricity usage
- Estimate monthly electricity consumption (30 days)
- Calculate billing cost based on tariff per kWh
- Save appliance data to file
- Save billing summary to file

---

## How It Works

The program stores data in two text files:

- `appliances.txt` – Stores appliance records
- `billing_summary.txt` – Stores saved billing summaries

Electricity usage formula:

```
kWh per day = (Watts / 1000) × Hours per day
```

Monthly estimates are calculated for 30 days.

---

## Requirements

- C++ compiler (e.g., g++)
- Standard C++ libraries:
  - iostream
  - fstream
  - string
  - iomanip
  - limits

---

## How to Compile

```bash
g++ main.cpp -o load_monitor
```

---

## How to Run

```bash
./load_monitor
```

---

## Menu Options

1. Register appliance
2. View appliances
3. Search appliance
4. Billing
5. Save to file
6. Exit

---

## Input Rules

- Maximum number of appliances: 100
- Appliance name must not be empty
- Watts must be greater than 0
- Hours per day must be between 0 and 24
- Tariff must be greater than 0

---

## Notes

- Appliance data is automatically loaded from `appliances.txt` when the program starts.
- Billing summaries are appended to `billing_summary.txt`.
- Data is saved automatically when adding appliances or exiting the program.

---

Simple and easy-to-use system for basic electrical load monitoring and electricity billing estimation.
