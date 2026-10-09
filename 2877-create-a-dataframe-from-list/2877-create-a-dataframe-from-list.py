import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    columns_name = ("student_id", "age")
    result_dataframe = pd.DataFrame(student_data, columns = columns_name)
    return result_dataframe