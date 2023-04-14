import boto3
from aws_cdk import (
    aws_ec2 as ec2,
    aws_elasticloadbalancingv2 as elbv2,
)

vpc = ec2.Vpc(self, "VPC", max_azs=2)
alb = elbv2.ApplicationLoadBalancer(self, "ALB", vpc=vpc, internet_facing=True)
#Create a listener for alb
alb_listener = elbv2.Listener(self, "ALBListener",
    port=80,
    protocol="HTTP",
    load_balancer_arn=alb.load_balancer_arn,
)