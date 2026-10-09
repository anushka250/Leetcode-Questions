import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    columns = ("name", "salary","bonus")
    employees['bonus'] = 2 * employees['salary']
    return employees