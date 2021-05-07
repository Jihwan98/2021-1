import numpy as np


class LinearRegression(object):
    def __init__(self, fit_intercept=True, copy_X=True):
        self.fit_intercept = fit_intercept
        self.copy_X = copy_X

        self._coef = None
        self._intercept = None
        self._new_X = None

    def fit(self, X, y):
        y = y.reshape(-1,1)
        if self.fit_intercept:
            self._new_X = np.concatenate((np.ones((X.shape[0], 1)), X), axis=1)
            weights = np.linalg.inv(self._new_X.T.dot(self._new_X)).dot(self._new_X.T).dot(y)
            self._intercept = weights[0].item()
            self._coef = weights[1:].flatten()
        else:
            self._new_X = X
            weights = np.linalg.inv(self._new_X.T.dot(self._new_X)).dot(self._new_X.T).dot(y)
            self._coef = weights.flatten()

    def predict(self, X):
        if self.fit_intercept:
            test_X = np.concatenate((np.ones((X.shape[0], 1)), X), axis=1)
            weights = np.concatenate(([self._intercept], self._coef), axis=0)
            return test_X.dot(weights)
        else:
            test_X = X
            weights = self._coef
            return test_X.dot(weights)
    @property
    def coef(self):
        return self._coef

    @property
    def intercept(self):
        return self._intercept
