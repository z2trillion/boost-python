import classtest
averager = classtest.RunningMean()
for i in range(10):
    averager.update(i)
    print 'updated with %i,' %i,
    print 'mean is now %f' %averager.getMean()
