# About Pandas
## Series
  - index 가 추가된 numpy이다
  ```
  from pandas import Series, DataFrame
  import pandas as pd
  
  list_data = [1,2,3,4,5]
  example_obj = Series(data = list_data)
  example_obj
  ```
  ```
  0    1
  1    2
  2    3
  3    4
  4    5
  dtype: int64
  ```
  
  ```
  list_data = [1,2,3,4,5]
  list_name = ["a","b","c","d","e"]
  example_obj = Series(data = list_data, index = list_name)
  example_obj
  ```
  ```
  a    1
  b    2
  c    3
  d    4
  e    5
  dtype: int64
  ```
  
  ```
  dic_data = {"a":1 , "b":2, "c":3, "d":4, "e":5}
  example_obj = Series(dic_data, dtype=np.float32, name="example_data")
  example_obj
  ```
  ```
  a    1.0
  b    2.0
  c    3.0
  d    4.0
  e    5.0
  Name: example_data, dtype: float32
  ```
  
  ```
  example_obj["a"]
  ```
  `1.0`
  ```
  example_obj["a"] = 3.2
  example_obj  
  ```
  ```
  a    3.2
  b    2.0
  c    3.0
  d    4.0
  e    5.0
  Name: example_data, dtype: float32
  ```
  
  ```
  example_obj.values
  ```
  `array([3.2, 2. , 3. , 4. , 5. ], dtype=float32)`
  ```
  example_obj.index
  ```
  `Index(['a', 'b', 'c', 'd', 'e'], dtype='object')`
  ```
  example_obj.name = "number"
  example_obj.index.name = "alphabet"
  example_obj
  ```
  ```
  alphabet
  a    3.2
  b    2.0
  c    3.0
  d    4.0
  e    5.0
  Name: number, dtype: float32
  ```
  
  [실행코드보기](./series.ipynb)
  
  
## DataFrame
  - DataFrame 생성
  ```
  raw_data = {'first_name': ['Jason', 'Molly', 'Tina', 'Jake', 'Amy'],
        'last_name': ['Miller', 'Jacobson', 'Ali', 'Milner', 'Cooze'],
        'age': [42, 52, 36, 24, 73],
        'city': ['San Francisco', 'Baltimore', 'Miami', 'Douglas', 'Boston']}
  df = pd.DataFrame(raw_data, columns = ['first_name', 'last_name', 'age', 'city'])
  df
  ```
  ```
  first_name	last_name	age	city
  0	Jason	Miller	42	San Francisco
  1	Molly	Jacobson	52	Baltimore
  2	Tina	Ali	36	Miami
  3	Jake	Milner	24	Douglas
  4	Amy	Cooze	73	Boston
  ```
  - 원하는 column 만 추출
  ```
  DataFrame(raw_data, columns = ["age", "city"])
  ```
  ```
  age	city
  0	42	San Francisco
  1	52	Baltimore
  2	36	Miami
  3	24	Douglas
  4	73	Boston
  ```
  - column 추가
  ```
  DataFrame(raw_data, columns = ["first_name","last_name","age", "city", "debt"])
  ```
  ```
  	first_name	last_name	age	city	debt
  0	Jason	Miller	42	San Francisco	NaN
  1	Molly	Jacobson	52	Baltimore	NaN
  2	Tina	Ali	36	Miami	NaN
  3	Jake	Milner	24	Douglas	NaN
  4	Amy	Cooze	73	Boston	NaN
  ```
  - column 선택 후 series 추출
  ```
  df = DataFrame(raw_data, columns = ["first_name", "last_name", "age", "city", "debt"])
  df.first_name    # == df["first_name"]
  ```
  ```
  0    Jason
  1    Molly
  2     Tina
  3     Jake
  4      Amy
  Name: first_name, dtype: object
  ```
  - loc - index location
  - iloc - index position
  ```
  df.loc[1]
  ```
  ```
  first_name        Molly
  last_name      Jacobson
  age                  52
  city          Baltimore
  debt                NaN
  Name: 1, dtype: object
  ```
  ```
  df["age"].iloc[1:]
  ```
  ```
  1    52
  2    36
  3    24
  4    73
  Name: age, dtype: int64
  ```
  - loc은 index 이름, iloc은 index number
  ```
  s = pd.Series(np.nan, index=[49,48,47,46,45, 1, 2, 3, 4, 5])
  s.loc[:3]
  ```
  ```
  49   NaN
  48   NaN
  47   NaN
  46   NaN
  45   NaN
  1    NaN
  2    NaN
  3    NaN
  dtype: float64
  ```
  ```
  s.iloc[:3]
  ```
  ```
  49   NaN
  48   NaN
  47   NaN
  dtype: float64
  ```
  - column에 새로운 데이터 할당
  ```
  df.debt = df.age > 40
  df
  ```
  ```
  	first_name	last_name	age	city	debt
  0	Jason	Miller	42	San Francisco	True
  1	Molly	Jacobson	52	Baltimore	True
  2	Tina	Ali	36	Miami	False
  3	Jake	Milner	24	Douglas	False
  4	Amy	Cooze	73	Boston	True
  ```
  - transpose `df.T`
  - 값 출력 `df.values`
  - csv 변환 `df.to_csv()`
  - column 삭제 `del df["debt"]`
  
  ```
  pop = {'Nevada': {2001: 2.4, 2002: 2.9},
 'Ohio': {2000: 1.5, 2001: 1.7, 2002: 3.6}}

  DataFrame(pop)
  ```
  ```
  	Nevada	Ohio
  2001	2.4	1.7
  2002	2.9	3.6
  2000	NaN	1.5
  ```
  
  [실행코드보기](./DataFrame.ipynb)

## Selection & Drop
  ### Selection with column names
  ```
  df = pd.read_excel("./data/excel-comp-data.xlsx")
  df.head()
  ```
  ```
      account	name	street	city	state	postal-code	Jan	Feb	Mar
  0	211829	Kerluke, Koepp and Hilpert	34456 Sean Highway	New Jaycob	Texas	28752	10000	62000	35000
  1	320563	Walter-Trantow	1311 Alvis Tunnel	Port Khadijah	NorthCarolina	38365	95000	45000	35000
  2	648336	Bashirian, Kunde and Price	62184 Schamberger Underpass Apt. 231	New Lilianland	Iowa	76517	91000	120000	35000
  3	109996	D'Amore, Gleichner and Bode	155 Fadel Crescent Apt. 144	Hyattburgh	Maine	46021	45000	120000	10000
  4	121213	Bauch-Goldner	7274 Marissa Common	Shanahanchester	California	49681	162000	120000	35000
  ```
  ```
  df["account"].head(3)    # df[["account","name","street"]].head() 여러개의 columns 추출 가능
  ```
  ```
  0    211829
  1    320563
  2    648336
  Name: account, dtype: int64
  ```
  ```
  df[:3]    # df["account"][:3] 원하는 columns 에서만도 가능
  ```
  ```
      account	name	street	city	state	postal-code	Jan	Feb	Mar
  0	211829	Kerluke, Koepp and Hilpert	34456 Sean Highway	New Jaycob	Texas	28752	10000	62000	35000
  1	320563	Walter-Trantow	1311 Alvis Tunnel	Port Khadijah	NorthCarolina	38365	95000	45000	35000
  2	648336	Bashirian, Kunde and Price	62184 Schamberger Underpass Apt. 231	New Lilianland	Iowa	76517	91000	120000	35000
  ```
  
  ### Series selection
  ```
  account_series = df["account"]
  account_series[:3]
  ```
  ```
  0    211829
  1    320563
  2    648336
  Name: account, dtype: int64
  ```
  ```
  account_series[[1,5,3]]
  ```
  ```
  1    320563
  5    132971
  3    109996
  Name: account, dtype: int64
  ```
  ```
  account_series[account_series>250000]
  ```
  ```
  1     320563
  2     648336
  13    268755
  14    273274
  Name: account, dtype: int64
  ```
  
  ### index 변경
  ```
  df.index = df["account"]
  del df["account"]
  df.head()
  ```
  ```
          name	street	city	state	postal-code	Jan	Feb	Mar
  account								
  211829	Kerluke, Koepp and Hilpert	34456 Sean Highway	New Jaycob	Texas	28752	10000	62000	35000
  320563	Walter-Trantow	1311 Alvis Tunnel	Port Khadijah	NorthCarolina	38365	95000	45000	35000
  648336	Bashirian, Kunde and Price	62184 Schamberger Underpass Apt. 231	New Lilianland	Iowa	76517	91000	120000	35000
  109996	D'Amore, Gleichner and Bode	155 Fadel Crescent Apt. 144	Hyattburgh	Maine	46021	45000	120000	10000
  121213	Bauch-Goldner	7274 Marissa Common	Shanahanchester	California	49681	162000	120000	35000
  ```
  
  ### Basic, loc, iloc selection
  ```
  df[["name","street"]][:2]    # Column 과 index number
  df.loc[[211829,320563],["name","street"]]    # Column 과 index name
  df.iloc[:2,:2]    # Column number 와 index number
  ```
  ```
        	name	street
  account		
  211829	Kerluke, Koepp and Hilpert	34456 Sean Highway
  320563	Walter-Trantow	1311 Alvis Tunnel
  ```
  ```
  df[["name","street"]].iloc[:5]
  ```
  ```
      name	street
  account		
  211829	Kerluke, Koepp and Hilpert	34456 Sean Highway
  320563	Walter-Trantow	1311 Alvis Tunnel
  648336	Bashirian, Kunde and Price	62184 Schamberger Underpass Apt. 231
  109996	D'Amore, Gleichner and Bode	155 Fadel Crescent Apt. 144
  121213	Bauch-Goldner	7274 Marissa Common
  ```
  
  ### index 재설정
  ```
  df.index = list(range(0,15))
  ```
  ### Data Drop
  ```
  df.drop([0,1,2,3])
  ```
  ```
  df.drop("city", axis=1)    # df.drop(["city","state"], axis=1) 여러개 없애기
  ```
  
  [실행코드보기](./Selection&Drop.ipynb)

## lambda, map, apply
  ### lambda 함수
  - 한 줄로 함수를 표현하는 익명 함수 기법
  - Lisp 언어에서 시작된 기법으로 오늘날 현대언어에 많이 사용
  - `lambda argument : expression`
  ```python
  def f(x, y):
    return x + y
    
  f = lambda x,y : x + y
  ```
  ```python
  f = lambda x, y: x + y
  f(1,4)
  ```
  `5`
  ```python
  (lambda x: x + 1)(5)
  ```
  `6`
  
  ### map 함수
  - 함수와 sequence형 데이터를 인자로 받아
  - 각 element 마다 입력받은 함수를 적용하여 list로 변환
  - 일반적으로 함수를 lambda 형태로 표현함
  - `map(function, sequence)`
  ```python
  ex = [1,2,3,4,5]
  f = lambda x: x**2
  list(map(f,ex))
  ```
  `[1, 4, 9, 16, 25]`
  - 두 개 이상의 argument가 있을 때는 두 개의 sequence형을 써야함
  ```python
  f = lambda x, y : x + y
  list(map(f,ex,ex))
  ```
  `[2, 4, 6, 8, 10]`
  - 익명 함수 그대로 사용할 수 있음
  ```python
  list(map(lambda x: x+x, ex))
  ```
  `[2, 4, 6, 8, 10]`
  
  ### map for series
  - Pandas의 series type의 데이터에도 map 함수 사용가능
  - function 대신 dict, sequence형 자료등으로 대체 가능
  - series 단위에서 많이 
  ```python
  s1 = Series(np.arange(10))
  s1.head(5)
  ```
  ```
  0    0
  1    1
  2    2
  3    3
  4    4
  dtype: int32
  ```
  ```python
  s1.map(lambda x: x**2).head(5)
  ```
  ```
  0     0
  1     1
  2     4
  3     9
  4    16
  dtype: int64
  ```
  ```python
  z = {1:'A',2:'B',3:'C'}
  s1.map(z).head(5)    # dict type 으로 데이터 교체, 없는 값은 NaN
  ```
  ```
  0    NaN
  1      A
  2      B
  3      C
  4    NaN
  dtype: object
  ```
  ```python
  s2 = Series(np.arange(10,20))
  s1.map(s2).head(5)    # 같은 위치의 데이터를 s2로 전환
  ```
  ```
  0    10
  1    11
  2    12
  3    13
  4    14
  dtype: int3
  ```
  - Example - map for seires (성별 1,0 으로 변환)
  ```python
  df = pd.read_csv("./data/wages.csv")
  df.sex.unique()
  ```
  `array(['male', 'female'], dtype=object)`
  ```python
  df["sex_code"] = df.sex.map({"male":0,"female":1})
  df.head(5)
  ```
  ```
    earn	height	sex	race	ed	age	sex_code
  0	79571.299011	73.89	male	white	16	49	0
  1	96396.988643	66.23	female	white	16	62	1
  2	48710.666947	63.77	female	white	16	33	1
  3	80478.096153	63.22	female	other	16	95	1
  4	82089.345498	63.08	female	white	17	43	1
  ```
  - lambda 로 height 나누기
  ```python
  df["height_level"] = df.height.map(lambda x: 'L' if x > 70 else('M' if x > 60 else 'S'))
  ```
  
  ### Replace function
  - map 함수의 기능 중 데이터 변환 기능만 담당
  - 데이터 변환시 많이 사용하는 함수
  ```python
  df.sex.replace({"male":0, "female":1}).head()    # dict type 적용
  ```
  ```
  0    0
  1    1
  2    1
  3    1
  4    1
  Name: sex, dtype: int64
  ```
  ```python
  df.sex.replace(["male","female"],[0,1],inplace=True)    # Target list, Conversion list, inplace -> 데이터 변환결과를 적용
  df.head(5)
  ```
  ```
    earn	height	sex	race	ed	age	sex_code	height_level
  0	79571.299011	73.89	0	white	16	49	0	L
  1	96396.988643	66.23	1	white	16	62	1	M
  2	48710.666947	63.77	1	white	16	33	1	M
  3	80478.096153	63.22	1	other	16	95	1	M
  4	82089.345498	63.08	1	white	17	43	1	M
  ```
  
  ### apply for DataFrame
  - map 과 달리, series 전체(columns)에 해당 함수를 적용
  - 입력값이 series 데이터로 입력받아 handling 가능
  - 내장 연산 함수를 사용할 때도 똑같은 효과를 거둘 수 있음
  - mean, std 등 사용가능
  - scalar 값 이외에 series 값의 반환도 가능함
  ```python
  df_info = df[["earn","height","age"]]
  
  f = lambda x : x.max() - x.min()
  df_info.apply(f)
  ```
  ```
  earn      318047.708444
  height        19.870000
  age           73.000000
  dtype: float64
  ```
  ```python
  df_info.sum()      # df_info.apply(sum)
  ```
  ```
  earn      4.474344e+07
  height    9.183125e+04
  age       6.250800e+04
  dtype: float64
  ```
  ```python
  def f(x):
    return Series([x.min(), x.max()], index = ["min","max"])
  df_info.apply(f)
  ```
  ```
      earn	height	age
  min	-98.580489	57.34	22
  max	317949.127955	77.21	95
  ```
  
  ### applymap for DataFrame
  - series 단위가 아닌 element 단위로 함수를 적용함
  - series 단위에 apply를 적용시킬 때와 같은 효과
  ```python
  f = lambda x: -x
  df_info.applymap(f).head(5)
  ```
  ```
  earn	height	age
  0	-79571.299011	-73.89	-49
  1	-96396.988643	-66.23	-62
  2	-48710.666947	-63.77	-33
  3	-80478.096153	-63.22	-95
  4	-82089.345498	-63.08	-43
  ```
  ```python
  df_info["earn"].apply(f).head(5)
  ```
  ```
  0   -79571.299011
  1   -96396.988643
  2   -48710.666947
  3   -80478.096153
  4   -82089.345498
  Name: earn, dtype: float64
  ```
  
  [실행코드보기](./lambda,map,apply.ipynb)
  

## DataFrame Operations
  ### Series Operation
  ```python
  s1 = Series(range(1,6), index=list("abcde"))
  s2 = Series(range(5,11), index=list("bcedef"))
  
  s1 + s2    # s1.add(s2)
  ```
  ```
  a     NaN
  b     7.0
  c     9.0
  d    12.0
  e    12.0
  e    14.0
  f     NaN
  dtype: float64
  ```
  ```python
  s1.add(s2, fill_value=0)    # fill_value : 빈 값에 값 넣어주기
  ```
  ```
  a     1.0
  b     7.0
  c     9.0
  d    12.0
  e    12.0
  e    14.0
  f    10.0
  ```
  
  ### DataFrame Operation
  ```python
  df1 = DataFrame(np.arange(9).reshape(3,3),columns=list("abc"))
  df2 = DataFrame(np.arange(16).reshape(4,4),columns=list("abcd"))
  df1 + df2
  ```
  ```
    a	b	c	d
  0	0.0	2.0	4.0	NaN
  1	7.0	9.0	11.0	NaN
  2	14.0	16.0	18.0	NaN
  3	NaN	NaN	NaN	NaN
  ```
  ```python
  df1.add(df2, fill_value = 0)
  ```
  ```
    a	b	c	d
  0	0.0	2.0	4.0	3.0
  1	7.0	9.0	11.0	7.0
  2	14.0	16.0	18.0	11.0
  3	12.0	13.0	14.0	15.0
  ```
  
  ### Series + DataFrame
  ```python
  df = DataFrame(np.arange(16).reshape(4,4), columns=list("abcd"))
  df
  ```
  ```
    a	b	c	d
  0	0	1	2	3
  1	4	5	6	7
  2	8	9	10	11
  3	12	13	14	15
  ```
  ```python
  s = Series(np.arange(10,14),index=list("abcd"))
  s
  ```
  ```
    a    10
  b    11
  c    12
  d    13
  dtype: int32
  ```
  ```python
  df + s    # column을 기준으로 broadcasting이 발생함
  ```
  ```
      a	b	c	d
  0	10	12	14	16
  1	14	16	18	20
  2	18	20	22	24
  3	22	24	26	28
  ```
  ```python
  s2 = Series(np.arange(10,14))
  s2
  ```
  ```
  0    10
  1    11
  2    12
  3    13
  dtype: int32
  ```
  ```python
  df + s2   # series index 와 DataFrame의 columns 이름이 매칭
  ```
  ```
    a	b	c	d	0	1	2	3
  0	NaN	NaN	NaN	NaN	NaN	NaN	NaN	NaN
  1	NaN	NaN	NaN	NaN	NaN	NaN	NaN	NaN
  2	NaN	NaN	NaN	NaN	NaN	NaN	NaN	NaN
  3	NaN	NaN	NaN	NaN	NaN	NaN	NaN	NaN
  ```
  ```python
  df.add(s2,axis=0)
  ```
  ```
    a	b	c	d
  0	10	11	12	13
  1	15	16	17	18
  2	20	21	22	23
  3	25	26	27	28
  ```
  
  [실행코드보기](./DataFrame_Operations.ipynb)
  
 
## Pandas builit-in functions
  ### describe
  - Numeric type 데이터의 요약 정보를 보여줌
  ```python
  df = pd.read_csv("./data/wages.csv")
  df.describe()
  ```
  ```
      earn	height	ed	age
  count	1379.000000	1379.000000	1379.000000	1379.000000
  mean	32446.292622	66.592640	13.354605	45.328499
  std	31257.070006	3.818108	2.438741	15.789715
  min	-98.580489	57.340000	3.000000	22.000000
  25%	10538.790721	63.720000	12.000000	33.000000
  50%	26877.870178	66.050000	13.000000	42.000000
  75%	44506.215336	69.315000	15.000000	55.000000
  max	317949.127955	77.210000	18.000000	95.000000
  ```
  
  ### unique
  - series data의 유일한 값을 list로 반환함
  ```python
  df.race.unique()
  ```
  `array(['white', 'other', 'hispanic', 'black'], dtype=object)`
  ```python
  np.array(dict(enumerate(df["race"].unique())))    # dict type 으로 index
  ```
  `array({0: 'white', 1: 'other', 2: 'hispanic', 3: 'black'}, dtype=object)`
  ```python
  value = list(map(int, np.array(list(enumerate(df['race'].unique())))[:,0].tolist()))
  key = np.array(list(enumerate(df['race'].unique())),dtype=str)[:,1].tolist()

  value, key
  ```
  `([0, 1, 2, 3], ['white', 'other', 'hispanic', 'black'])`
  ```python
  df["race"].replace(to_replace=key, value=value, inplace=True)
  
  value = list(map(int, np.array(list(enumerate(df['sex'].unique())))[:,0].tolist()))
  key = np.array(list(enumerate(df['sex'].unique())),dtype=str)[:,1].tolist()

  value, key
  ```
  `([0, 1], ['male', 'female'])`
  ```python
  df["sex"].replace(to_replace=key, value=value, inplace=True)
  df.head(5)
  ```
  ```
    earn	height	sex	race	ed	age
  0	79571.299011	73.89	0	0	16	49
  1	96396.988643	66.23	1	0	16	62
  2	48710.666947	63.77	1	0	16	33
  3	80478.096153	63.22	1	1	16	95
  4	82089.345498	63.08	1	0	17	43
  ```
  
  ### Sum
  - 기본적인 column 또는 row 값의 연산을 지원
  - sub, mean, min, max, count, median, mad, var 등
  ```python
  df.sum(axis=0)   # column 별
  df.sum(axis=1)    # row 별
  ```
  
  ### innull
  - column 또는 row 값의 NaN(null) 값의 index를 반환함
  ```python
  df.isnull().head()
  ```
  ```
    earn	height	sex	race	ed	age
  0	False	False	False	False	False	False
  1	False	False	False	False	False	False
  2	False	False	False	False	False	False
  3	False	False	False	False	False	False
  4	False	False	False	False	False	False
  ```
  ```python
  df.isnull().sum()
  ```
  ```
  earn      0
  height    0
  sex       0
  race      0
  ed        0
  age       0
  dtype: int64
  ```
  
  ### sort_values
  - column 값을 기준으로 데이터를 sorting
  ```python
  df.sort_values(["age","earn"], ascending=True).head(10)
  ```
  ```
        earn	height	sex	race	ed	 age
  1038	-56.321979	67.81	male	2	10	22
  800	-27.876819	72.29	male	0	12	22
  963	-25.655260	68.90	male	0	12	22
  1105	988.565070	64.71	female	0	12	22
  801	1000.221504	64.09	female	0	12	22
  862	1002.023843	66.59	female	0	12	22
  933	1007.994941	68.26	female	0	12	22
  988	1578.542814	64.53	male	0	12	22
  522	1955.168187	69.87	female	3	12	22
  765	2581.870402	64.79	female	0	12	22
  ```
  
  ### etc
  - df.cumsum()
  - df.cummax()
  
  ### Correlation & Covariance
  - 상관계수와 공분산을 구하는 함수
  - corr, cov, corrwith
  ```python
  df.age.corr(df.earn)
  ```
  `0.07400349177836055`
  ```python
  df.age.cov(df.earn)
  ```
  `36523.69921040889`
  ```python
  df.corrwith(df.earn)
  ```
  ```
  earn      1.000000
  height    0.291600
  race     -0.063977
  ed        0.350374
  age       0.074003
  dtype: float64
  ```
  ```python
  df.corr()
  ```
  ```
        earn	height	race	ed	age
  earn	1.000000	0.291600	-0.063977	0.350374	0.074003
  height	0.291600	1.000000	-0.045974	0.114047	-0.133727
  race	-0.063977	-0.045974	1.000000	-0.049487	-0.056879
  ed	0.350374	0.114047	-0.049487	1.000000	-0.129802
  age	0.074003	-0.133727	-0.056879	-0.129802	1.000000
  ```
  
  [실행코드보기](./built-in_functions.ipynb)
