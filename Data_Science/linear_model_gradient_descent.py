import numpy as np


class LinearRegressionGD(object):
    def __init__(self, fit_intercept=True, copy_X=True,
                 eta0=0.001, epochs=1000, weight_decay=0.9):
        self.fit_intercept = fit_intercept
        self.copy_X = copy_X
        self._eta0 = eta0
        self._epochs = epochs

        self._cost_history = []

        self._coef = None
        self._intercept = None
        self._new_X = None
        self._w_history = []
        self._weight_decay = weight_decay

    def cost(self, h, y):
        return (1/(2*len(y)) * np.sum((h-y)**2))

    def hypothesis_function(self, X, theta):
        return X.dot(theta)

    def gradient(self, X, y, theta):
        return np.array([np.sum((np.dot(X, theta) - y) * X[:,i]) for i in range(len(theta))])


    def fit(self, X, y):
        self._new_X = X
        m = len(y)
        if self.fit_intercept:
            self._new_X = np.concatenate((np.ones((len(X), 1)), X), axis=1)

        theta = np.random.normal(size=(1,self._new_X.shape[1])).flatten()
        for epoch in range(self._epochs):
            gradient = self.gradient(self._new_X, y, theta).flatten()
            theta_list = []
            for i in range(len(theta)):
                theta_list.append(theta[i] - (self._eta0 / m) * gradient[i])

            theta = np.array(theta_list)
            
            if epoch % 100 == 0:
                self._w_history.append(theta.tolist())
                cost = self.cost(self.hypothesis_function(self._new_X, theta), y)
                self._cost_history.append(cost)
            self._eta0 = self._eta0 * self._weight_decay

        if self.fit_intercept:
            self._intercept = theta[0].item()
            self._coef = theta[1:].flatten()
        else:
            self._coef = theta.flatten()
        

    def predict(self, X):
        test_X = X

        if self.fit_intercept:
            test_X = np.concatenate((np.ones([len(test_X), 1]), test_X), axis=1)
            weights = np.concatenate(([self._intercept], self._coef), axis=0)
        else:
            weights = self._coef

        return test_X.dot(weights)

    @property
    def coef(self):
        return self._coef

    @property
    def intercept(self):
        return self._intercept

    @property
    def weights_history(self):
        return np.array(self._w_history)

    @property
    def cost_history(self):
        return self._cost_history